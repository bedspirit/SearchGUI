document.addEventListener('DOMContentLoaded', function() {
	const searchFor = document.getElementById('searchFor');
	const fileName = document.getElementById('fileName');
	const searchButton = document.getElementById('searchButton');
	const andButton = document.getElementById('andButton');
	const orButton = document.getElementById('orButton');
	const fromDateInput = document.getElementById('fromDate');
	const toDateInput = document.getElementById('toDate');
	const today = new Date();
	const lastWeek = new Date();
	
	lastWeek.setDate(today.getDate() - 7); // Subtract 7 days to get last week's date
	flatpickr(fromDateInput, {
		dateFormat: 'm/d/Y',
		defaultDate: lastWeek, // Set default "from" date to last week
		onClose: function(selectedDates, dateStr, instance) {
			toDateInput._flatpickr.show();
		}
	});
	flatpickr(toDateInput, {
		dateFormat: 'm/d/Y',
		defaultDate: today, // Set default "to" date to today
		onClose: function(selectedDates, dateStr, instance) {
			console.log('Selected "To" Date:', dateStr);
		}
	});
	searchButton.addEventListener('click', function() {
		document.getElementById('searchResultsItems').classList.toggle('hidden');
		document.getElementById('searchResultsItems2').classList.toggle('hidden');
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
});
