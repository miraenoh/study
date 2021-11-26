const h1 = document.querySelector('.hello h1')

function handleMouseEnter() {
	h1.innerText = 'Mouse is here!'
}

function handleMouseLeave() {
	h1.innerText = 'Mouse is gone!'
}

function handleWindowResize() {
	document.body.style.backgroundColor = 'tomato'
}

function handleWindowCopy() {
	alert('copier!')
}

function handleWindowOffline() {
	alert('SOS no WIFI')
}

function handleWindowOnline() {
	alert('ALL GOOOD')
}

// Option 1
h1.onclick = () => {
	h1.style.color = 'blue'
}

// Option 2
h1.addEventListener('mouseenter', handleMouseEnter)
h1.addEventListener('mouseleave', handleMouseLeave)

window.addEventListener('resize', handleWindowResize)
window.addEventListener('copy', handleWindowCopy)
window.addEventListener('offline', handleWindowOffline)
window.addEventListener('online', handleWindowOnline)
window.oncontextmenu = () => {
	h1.style.color = 'red'
	h1.innerText = 'Right click!'
}
