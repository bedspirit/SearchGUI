document.addEventListener('DOMContentLoaded', function() {
	let container = document.querySelector('.components');
	const searchFor = document.getElementById('searchFor');
	const fileName = document.getElementById('fileName');
	const searchButton = document.getElementById('searchButton');
	const andButton = document.getElementById('andButton');
	const orButton = document.getElementById('orButton');
	const fromDateInput = document.getElementById('fromDate');
	const toDateInput = document.getElementById('toDate');
	const today = new Date();
	const lastWeek = new Date();
	const searchResults = document.getElementById("searchResults");
	
	lastWeek.setDate(today.getDate() - 7); // Subtract 7 days to get last week's date
	flatpickr(fromDateInput, {
		dateFormat: 'm/d/Y',
		defaultDate: lastWeek, // Set default "from" date to last week
	//	onClose: function(selectedDates, dateStr, instance) {
	//		toDateInput._flatpickr.show();
	//	}
	});
	flatpickr(toDateInput, {
		dateFormat: 'm/d/Y',
		defaultDate: today, // Set default "to" date to today
		onClose: function(selectedDates, dateStr, instance) {
			console.log('Selected "To" Date:', dateStr);
		}
	});
	andButton.addEventListener('click', function() {
		var inputElement = document.getElementById('searchFor');
		var currentValue = inputElement.value;
		
		if(currentValue.trim() !== ''){
			inputElement.value = currentValue + ';';
		}
	});
	orButton.addEventListener('click', function() {
		var inputElement = document.getElementById('fileName');
		var currentValue = inputElement.value;
		
		if(currentValue.trim() !== ''){
			inputElement.value = currentValue + ';';
		}
	});
	function searchButtonClick() {
		let num = 1;
		if (!searchButtonClicked) {
			searchButtonClicked = true;
			console.log('Button Clicked');
			searchResultsItems.innerHTML='';
			const results = [
				{ linkBut: "fileName1", fileDate: "Date1", fileSize: "Size1", snippet: "Sample from file" },
				{ linkBut: "fileName2", fileDate: "Date2", fileSize: "Size2", snippet: "Sample from file" },
				{ linkBut: "fileName2", fileDate: "Date2", fileSize: "Size2", snippet: "Sample from file" },
				{ linkBut: "fileName2", fileDate: "Date2", fileSize: "Size2", snippet: "Sample from file" },
		  // ... more results
			];
			results.forEach(resultItem => {
				const resultDiv = document.createElement("div");
				resultDiv.className = "searchResults"; // Initially hidden due to CSS class
				resultDiv.innerHTML = `<div class="linkButton linkButton__primary"><p>${resultItem.linkBut}</p></div><div class="date_size"><div class="date_size__dateResult"><p>${resultItem.fileDate}</p></div><div class="date_size__sizeResult"><p>${resultItem.fileSize}</p></div></div><div class="preview"><p>${resultItem.snippet}</p></div></div>`;

				searchResultsItems.appendChild(resultDiv);

		  // Adding a small delay before adding the "visible" class to trigger the animation
		  		setTimeout(() => {
					container.classList.add("visible");
				}, 50 * results.indexOf(resultItem));				
				setTimeout(() => {
					resultDiv.classList.add("visible");
				}, 100 * results.indexOf(resultItem));				
				});
			setTimeout(() => {
			searchButtonClicked = false;
			}, 10000); // Set a timeout to reset the flag after a certain delay
		}
	}

	 let searchButtonClicked = false;
	searchButton.addEventListener('click', searchButtonClick);
});
