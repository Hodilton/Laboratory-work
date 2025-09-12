import React from 'react';
import './App.css';
import UserList from './components/UserList';

function App() {
  return (
    <div className="App">
      <header className="header">
        <h1>User List</h1>
      </header>
      <main>
        <UserList />
      </main>
    </div>
  );
}

export default App;
