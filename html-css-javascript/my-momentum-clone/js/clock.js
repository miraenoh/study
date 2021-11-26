// setInterval(), setTimeout(), Date, padStart(), padEnd()

const clock = document.querySelector('#clock')

function getClock() {
	const date = new Date()
	const hours = String(date.getHours()).padStart(2, '0')
	const minutes = String(date.getMinutes()).padStart(2, '0')
	const seconds = String(date.getSeconds()).padStart(2, '0')

	clock.innerText = `${hours}:${minutes}:${seconds}`
}

// setInterval: *ms마다 지정된 함수 실행(반복)
getClock()
setInterval(getClock, 1000)

// setTimeout: *ms후에 지정된 함수 실행(한 번)
// setTimeout(getClock, 5000)
