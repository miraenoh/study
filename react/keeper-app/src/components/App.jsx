import React, { useState } from 'react';
import Footer from './Footer';
import Header from './Header';
import Note from './Note';
import CreateArea from './CreateArea';

export default function App() {
	const [notes, setNotes] = useState([]);

	function addNote(newNote) {
		setNotes((prevNotes) => [...prevNotes, newNote]);
	}

	function deleteNote(id) {
		setNotes((prevNotes) => prevNotes.filter((note, index) => index !== id));
	}

	return (
		<div>
			<Header />
			<CreateArea onAdd={addNote} />
			{notes.map((noteItem, index) => (
				<Note key={index} id={index} {...noteItem} onDelete={deleteNote} />
			))}
			<Footer />
		</div>
	);
}
