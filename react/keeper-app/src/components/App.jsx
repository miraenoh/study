import React from 'react';
import notes from '../notes';
import Footer from './Footer';
import Header from './Header';
import Note from './Note';

export default function App() {
	return (
		<div>
			<Header />
			{notes.map((noteData) => (
				<Note {...noteData} />
			))}
			<Footer />
		</div>
	);
}
