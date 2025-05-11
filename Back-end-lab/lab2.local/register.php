<?php
require 'db_connect.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];
    $email = $_POST['email'];
    $birthdate = $_POST['birthdate'];
    $language = $_POST['language'];

    $passwordHash = hash('sha256', $password);
    $activationToken = bin2hex(random_bytes(16));

    try {
        $stmt = $pdo->prepare("INSERT INTO users (Login, Password, Email, BirthDate, ProgrammingLanguage, IsActive, ActivationToken) 
                               VALUES (:username, :password, :email, :birthdate, :language, 0, :token)");
        $stmt->execute([
            'username' => $username,
            'password' => $passwordHash,
            'email' => $email,
            'birthdate' => $birthdate,
            'language' => $language,
            'token' => $activationToken,
        ]);

        $activationLink = "http://" . $_SERVER['HTTP_HOST'] . "/?page=activate&token=" . $activationToken;
        echo "Регистрация успешна! Пожалуйста, активируйте аккаунт по <a href='$activationLink'>ссылке</a>.";
    } catch (PDOException $e) {
        echo "Ошибка: " . $e->getMessage();
    }
}
?>

<form method="POST">
    <label for="username">Логин:</label>
    <input type="text" name="username" required>
    <br>

    <label for="password">Пароль:</label>
    <input type="password" name="password" required>
    <br>

    <label for="email">Email:</label>
    <input type="email" name="email" required>
    <br>

    <label for="birthdate">Дата рождения:</label>
    <input type="date" name="birthdate" required>
    <br>

    <label for="language">Изучаемый язык программирования:</label>
    <select name="language" required>
        <option value="Python">Python</option>
        <option value="JavaScript">JavaScript</option>
        <option value="YoptaScript">YoptaScript</option>
        <option value="Java">Java</option>
        <option value="C++">C++</option>
        <option value="PHP">PHP</option>
        <option value="Other">Другой</option>
    </select>
    <br>

    <button type="submit">Зарегистрироваться</button>
</form>