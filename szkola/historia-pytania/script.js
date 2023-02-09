function changeall() {
	details = document.querySelectorAll('details');
	button = document.querySelector('button');
	for(let i = 0; i < details.length; i++) {
		if(button.innerHTML === 'OPEN')
			details[i].setAttribute('open', '');
		else if(button.innerHTML === 'CLOSE')
			details[i].removeAttribute('open');
	}
	if(button.innerHTML === 'OPEN')
		button.innerHTML = 'CLOSE';
	else if(button.innerHTML === 'CLOSE')
		button.innerHTML = 'OPEN';
}
document.onmousedown = function(e) {
	if(e.target.tagName.toLowerCase() === 'summary' && e.detail > 1)
		e.preventDefault();
};
document.querySelector('button').onclick = changeall;
