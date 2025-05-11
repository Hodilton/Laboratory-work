<?php
require 'db_connect.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    $passwordHash = hash('sha256', $password);

    $stmt = $pdo->prepare("SELECT * FROM users WHERE Login = :username AND Password = :password AND IsActive = 1");
    $stmt->execute([
        'username' => $username,
        'password' => $passwordHash,
    ]);

    if ($stmt->rowCount() > 0) {
        echo "Авторизация успешна!";
    } else {
        echo "Неверный логин, пароль или аккаунт не активирован.";
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
    <button type="submit">Войти</button>
</form>
