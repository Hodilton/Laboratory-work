function submit() {
    const fullname = document.getElementById('name').value.trim();
    const birthday = document.getElementById('birthday').value;
    const phone = document.getElementById('phone').value.trim();
    const mail = document.getElementById('mail').value.trim();
    const music = document.getElementById('music').value;

    if (!fullname || !birthday || !phone || !mail) {
        alert("Пожалуйста, заполните все обязательные поля.");
        return;
    }

    const age = Math.floor((new Date() - new Date(birthday).getTime()) / 3.15576e+10);

    let letters = {};
    fullname.replace(/\s/g, '').split('').forEach(char => {
        letters[char] = (letters[char] || 0) + 1;
    });

    const mostCommon = Object.entries(letters).reduce((a, b) => (b[1] > a[1] ? b : a));

    const atPosition = mail.indexOf('@');
    const symbolsBeforeAt = atPosition !== -1 ? atPosition : 0;

    alert(`
        Ваше полное имя: ${fullname}
        Ваша дата рождения: ${birthday} (Вам ${age} лет)
        Ваш номер телефона: ${phone}
        Ваш email: ${mail}
        Любимый музыкальный жанр: ${music || "Нету"}
        Самая частая буква в имени: ${mostCommon[0]} (${mostCommon[1]} раз)
        Количество символов до @: ${symbolsBeforeAt}
    `);
}

document.getElementById('submit-button').addEventListener('click', submit);