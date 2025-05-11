<?php
include 'db_config.php';

$conn = new mysqli($host, $user, $password, $db_name);

if ($conn->connect_error) {
    die("Ошибка подключения: " . $conn->connect_error);
}

$sql = "SELECT * FROM users";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<table border='1' style='border-collapse: collapse; width: 100%;'>";
    echo "<thead>";
    echo "<tr>
            <th>ID</th>
            <th>Name</th>
            <th>Nickname</th>
            <th>Hobby</th>
            <th>City</th>
            <th>Country</th>
            <th>Email</th>
            <th>Data</th>
          </tr>";
    echo "</thead>";
    echo "<tbody>";

    while ($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>{$row['ID']}</td>
                <td>{$row['Name']}</td>
                <td>{$row['Nickname']}</td>
                <td>{$row['Hobbi']}</td>
                <td>{$row['City']}</td>
                <td>{$row['Country']}</td>
                <td>{$row['Email']}</td>
                <td>{$row['Data']}</td>
              </tr>";
    }
    echo "</tbody>";
    echo "</table>";
} else {
    echo "Данные отсутствуют.";
}

$conn->close();
?>