document.addEventListener('contextmenu', function(event) {
    event.preventDefault();
    const contextMenu = document.getElementById('contextMenu');
    if (event.clientY > 50) {
        contextMenu.style.top = `${event.clientY}px`;
        contextMenu.style.left = `${event.clientX}px`;
        contextMenu.style.display = 'block';
    } else {
        contextMenu.style.display = 'none';
    }
});

document.addEventListener('click', function() {
    const contextMenu = document.getElementById('contextMenu');
    contextMenu.style.display = 'none';
});