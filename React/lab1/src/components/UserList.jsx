import React, { useState, useEffect } from 'react';
import UserCard from './UserCard';
import './user-list.css';

const UserList = () => {
  const [users, setUsers] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    const fetchUsers = async () => {
      try {
        setLoading(true);
        const res = await fetch('https://randomuser.me/api/?results=8');
        if (!res.ok) throw new Error(`Ошибка: ${res.status}`);
        
        const data = await res.json();

        const formattedUsers = data.results.map((u, index) => ({
          id: index,
          first_name: u.name.first,
          last_name: u.name.last,
          email: u.email,
          avatar: u.picture.medium
        }));

        setUsers(formattedUsers);
      } catch (err) {
        setError(err.message);
      } finally {
        setLoading(false);
      }
    };

    fetchUsers();
  }, []);

  if (loading) return <div className="loading">Загрузка пользователей…</div>;
  if (error) return <div className="error">Ошибка: {error}</div>;

  return (
    <div className="user-list">
      <h2>Список пользователей</h2>
      <div className="users-container">
        {users.map(user => <UserCard key={user.id} user={user} />)}
      </div>
    </div>
  );
};

export default UserList;
