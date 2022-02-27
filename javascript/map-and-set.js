let messages = [
	{ text: 'Hello', from: 'John' },
	{ text: 'How goes?', from: 'John' },
	{ text: 'See you soon', from: 'Alice' }
];

let readMessages = new WeakSet();
for (const message of messages) {
	readMessages.add(message);
}
console.log(readMessages.has(messages[0]));

let timeReadMessages = new WeakMap();
for (const message of messages) {
	timeReadMessages.set(message, Date());
}
console.log(timeReadMessages.get(messages[1]))
