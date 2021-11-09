interface Human {
	name: string
	age: number
	gender: string
}

const person = {
	name: 'Mirae',
	age: 25,
	gender: 'female'
}

const sayHi = (person: Human): string => {
	return `Hello ${person.name}, you are ${person.age} and you are a ${person.gender}!`
}

console.log(sayHi(person))

export {}
