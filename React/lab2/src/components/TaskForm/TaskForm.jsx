// src/components/TaskForm/TaskForm.jsx

import { useState } from 'react';
import { CATEGORIES } from '../../utils/constants.js';
import Input from '../common/Input/Input.jsx';
import Button from '../common/Button/Button.jsx';
import styles from './TaskForm.module.css';

const TaskForm = ({ onAddTask }) => {
  const [text, setText] = useState('');
  const [categoryId, setCategoryId] = useState(CATEGORIES[0].id);

  const handleSubmit = (e) => {
    e.preventDefault();
    if (text.trim()) {
      onAddTask(text.trim(), categoryId);
      setText('');
    }
  };

  return (
    <form onSubmit={handleSubmit} className={styles.form}>
      <Input
        value={text}
        onChange={(e) => setText(e.target.value)}
        placeholder="Введите задачу..."
        className={styles.input}
      />
      <select 
        value={categoryId} 
        onChange={(e) => setCategoryId(e.target.value)}
        className={styles.select}
      >
        {CATEGORIES.map(cat => (
          <option key={cat.id} value={cat.id}>
            {cat.name}
          </option>
        ))}
      </select>
      <Button type="submit">Добавить</Button>
    </form>
  );
};

export default TaskForm;
