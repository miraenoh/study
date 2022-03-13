import React, { useState } from 'react';
import AddIcon from '@material-ui/icons/Add';
import Fab from '@material-ui/core/Fab';
import Zoom from '@material-ui/core/Zoom';

function CreateArea(props) {
	const [isExpanded, setIsExpanded] = useState(false);
	const [note, setNote] = useState({
		title: '',
		content: ''
	});

	function expand() {
		setIsExpanded(true);
	}

	function handleChange(event) {
		const { name, value } = event.target;
		setNote((prevNote) => ({ ...prevNote, [name]: value }));
	}

	function handleSubmit(event) {
		event.preventDefault();

		props.onAdd(note);
		setNote({ title: '', content: '' });
		setIsExpanded(false);
	}

	return (
		<div>
			<form className="create-note" onSubmit={handleSubmit}>
				{isExpanded && <input name="title" value={note.title} placeholder="Title" onChange={handleChange} />}
				<textarea name="content" value={note.content} placeholder="Take a note..." rows={isExpanded ? 3 : 1} onChange={handleChange} onClick={expand} />
				<Zoom in={isExpanded}>
					<Fab type="submit">
						<AddIcon />
					</Fab>
				</Zoom>
			</form>
		</div>
	);
}

export default CreateArea;
