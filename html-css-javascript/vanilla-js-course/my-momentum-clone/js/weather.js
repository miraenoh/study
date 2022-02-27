const API_KEY = 'e33ee0dc69721897877bba4af2f35f96'

function onGeoSuccess(position) {
	const lat = position.coords.latitude
	const lon = position.coords.longitude

	const url = `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&units=metric&appid=${API_KEY}`
	fetch(url)
		.then((res) => res.json())
		.then((data) => {
			const weather = document.querySelector('#weather div:first-child')
			const city = document.querySelector('#weather div:last-child')

			city.innerText = data.name
			weather.innerText = `${data.weather[0].main} ${data.main.temp}`
		})
}

function onGeoError() {
	alert("Can't find you. No weather for you.")
}

navigator.geolocation.getCurrentPosition(onGeoSuccess, onGeoError)
