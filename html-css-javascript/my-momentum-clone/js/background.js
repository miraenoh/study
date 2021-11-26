const images = ['bg-1.jpg', 'bg-2.jpg', 'bg-3.jpg', 'bg-4.jpg', 'bg-5.jpg']
const chosenImage = images[Math.floor(Math.random() * images.length)]

const bgImage = document.getElementById('background-image')
bgImage.style.backgroundImage = `url('img/${chosenImage}')`
