const loginForm = document.querySelector('#login-form')
const loginInput = loginForm.querySelector('input')
const greeting = document.querySelector('#greeting')

const HIDDEN_CLASSNAME = 'hidden'
const USERNAME_KEY = 'username'

function handleLoginSubmit(event) {
	// Submit 동작으로 인한 기본행동(브라우저 새로고침)을 막음
	event.preventDefault()

	loginForm.classList.add(HIDDEN_CLASSNAME)
	const username = loginInput.value
	localStorage.setItem(USERNAME_KEY, username)
	paintGreetings(username)
}

function paintGreetings(username) {
	greeting.innerText = `Have a good day, ${username}.`
	greeting.classList.remove(HIDDEN_CLASSNAME)
}

const savedUsername = localStorage.getItem(USERNAME_KEY)

if (savedUsername === null) {
	// Show the form
	loginForm.classList.remove(HIDDEN_CLASSNAME)
	loginForm.addEventListener('submit', handleLoginSubmit)
} else {
	// Show the greetings
	paintGreetings(savedUsername)
}
