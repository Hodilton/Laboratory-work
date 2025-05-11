import React, { useState } from 'react';
import './Register.css';

export default function Register() {
    const [formData, setFormData] = useState({
        surname: '',
        name: '',
        fatherName: '',
        sex: '',
        login: '',
        email: '',
        pass1: '',
        pass2: ''
    });

    const [message, setMessage] = useState('');

    const changeInputRegister = (event) => {
        const { name, value } = event.target;
        setFormData((prev) => ({
            ...prev,
            [name]: value
        }));
    };

    const handleSubmit = (event) => {
        event.preventDefault();
        setMessage('');

        const { surname, name, login, email, pass1, pass2 } = formData;

        // Проверка имени и фамилии
        if (surname.length < 2 || name.length < 2) {
            setMessage("Введите имя и фамилию");
            return;
        }

        // Проверка логина
        if (login.length < 7) {
            setMessage("Логин должен содержать не менее 7 символов");
            return;
        }

        // Проверка email
        const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        if (!emailRegex.test(email)) {
            setMessage("Введите правильный email-адрес");
            return;
        }

        // Проверка пароля
        if (pass1 !== pass2) {
            setMessage("Пароли не совпадают");
            return;
        }
        if (pass1.length < 8) {
            setMessage("Пароль должен содержать не менее 8 символов");
            return;
        }

        alert("Аккаунт зарегистрирован");

        // Здесь вы можете отправить данные на сервер через axios или fetch
    };

    const handleReset = () => {
        setFormData({
            surname: '',
            name: '',
            fatherName: '',
            sex: '',
            login: '',
            email: '',
            pass1: '',
            pass2: ''
        });
        setMessage('');
    };

    return (
        <fieldset>
            <legend>Регистрация учётной записи</legend>
            <form onSubmit={handleSubmit}>
                <div className="flexbox">
                    <div>
                        <p>Фамилия:</p>
                        <input name="surname" type="text" value={formData.surname} onChange={changeInputRegister} required />
                        <p>Имя:</p>
                        <input name="name" type="text" value={formData.name} onChange={changeInputRegister} required />
                        <p>Отчество:</p>
                        <input name="fatherName" type="text" value={formData.fatherName} onChange={changeInputRegister} />
                        <p>Пол:</p>
                        <select name="sex" value={formData.sex} onChange={changeInputRegister} required>
                            <option value="">Пол</option>
                            <option value="male">Мужской</option>
                            <option value="female">Женский</option>
                        </select>
                    </div>
                    <div>
                        <p>Логин:</p>
                        <input name="login" type="text" value={formData.login} onChange={changeInputRegister} required />
                        <p>Электронная почта:</p>
                        <input name="email" type="email" value={formData.email} onChange={changeInputRegister} required />
                        <p>Пароль:</p>
                        <input name="pass1" type="password" value={formData.pass1} onChange={changeInputRegister} required />
                        <p>Повторите пароль:</p>
                        <input name="pass2" type="password" value={formData.pass2} onChange={changeInputRegister} required />
                    </div>
                </div>
                <button type="submit">Отправить</button>
                <button type="button" onClick={handleReset}>Сброс</button>
            </form>
            {message && <p>{message}</p>}
        </fieldset>
    );
}

