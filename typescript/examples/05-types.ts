const name = 'Mirae',
	age = 25,
	gender = 'female'

const sayHi = (name: string, age: number, gender: string): string => {
	return `Hello ${name}, you are ${age} and you are a ${gender}!`
}

console.log(sayHi('Mirae', 25, 'female'))

export {}
