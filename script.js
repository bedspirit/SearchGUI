document.addEventListener('DOMContentLoaded', function() {
  const input1 = document.getElementById('input1');
  const input2 = document.getElementById('input2');
  const submitButton = document.getElementById('submitButton');
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
  submitButton.addEventListener('click', function() {
    const value1 = input1.value;
    const value2 = input2.value;
    console.log('Input 1:', value1);
    console.log('Input 2:', value2);
  });
});
