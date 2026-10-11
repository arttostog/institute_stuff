const visitorForm = document.getElementById("visitor-form");

const name = document.getElementById('visitor-name');
const age = document.getElementById('visitor-age');
const gender = document.getElementById('visitor-gender');
const interestYourself = document.getElementById('visitor-interest-yourself');
const commentary = document.getElementById('visitor-commentary');

visitorForm.addEventListener("submit", (event) => {
    event.preventDefault();
	
	const form = {
		name: name.value,
		age: age.value,
		gender: gender.value,
		interest: [],
		interestYourself: interestYourself.value,
		commentary: commentary.value,
	};

	for (let checked of document.querySelectorAll('input[type="checkbox"]:checked'))
		form.interest.push(checked)
	
	if (age.value < 0 || age.value > 120) {
		alert("Указан некорректный возраст!");
		return;
	}

	alert("Ну... допустим форма отправлена на сервер");
});