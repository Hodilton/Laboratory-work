<?php
require 'db_connect.php';

if (isset($_GET['token'])) {
    $token = $_GET['token'];

    $stmt = $pdo->prepare("SELECT * FROM users WHERE ActivationToken = :token AND IsActive = 0");
    $stmt->execute(['token' => $token]);

    if ($stmt->rowCount() > 0) {
        $updateStmt = $pdo->prepare("UPDATE users SET IsActive = 1, ActivationToken = NULL WHERE ActivationToken = :token");
        $updateStmt->execute(['token' => $token]);
        echo "Аккаунт успешно активирован! Теперь вы можете войти.";
    } else {
        echo "Неверный или уже использованный токен.";
    }
} else {
    echo "Токен активации не найден.";
}
?>