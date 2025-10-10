// src/components/TaskItem/TaskItem.jsx

import Checkbox from '../common/Checkbox/Checkbox.jsx';
import Button from '../common/Button/Button.jsx';
import { CATEGORIES } from '../../utils/constants.js';
import styles from './TaskItem.module.css';
import { useState } from 'react';

const TaskItem = ({ task, onToggle, onDelete, onEdit }) => {
  const category = CATEGORIES.find(c => c.id === task.categoryId)?.name || '—';
  const [isEditing, setIsEditing] = useState(false);
  const [editText, setEditText] = useState(task.text);
  const [editCategory, setEditCategory] = useState(task.categoryId);

  const handleEdit = () => {
    if (editText.trim()) {
      onEdit(task.id, editText.trim(), editCategory);
      setIsEditing(false);
    }
  };

  const handleCancel = () => {
    setEditText(task.text);
    setEditCategory(task.categoryId);
    setIsEditing(false);
  };

  if (isEditing) {
    return (
      <div className={styles.item}>
        <div className={styles.editForm}>
          <input
            type="text"
            value={editText}
            onChange={(e) => setEditText(e.target.value)}
            className={styles.editInput}
          />
          <select
            value={editCategory}
            onChange={(e) => setEditCategory(e.target.value)}
            className={styles.editSelect}
          >
            {CATEGORIES.map(cat => (
              <option key={cat.id} value={cat.id}>
                {cat.name}
              </option>
            ))}
          </select>
        </div>
        <div className={styles.editButtons}>
          <Button variant="primary" onClick={handleEdit} className={styles.editButton}>
            Сохранить
          </Button>
          <Button variant="secondary" onClick={handleCancel} className={styles.editButton}>
            Отмена
          </Button>
        </div>
      </div>
    );
  }

  return (
    <div className={`${styles.item} ${task.completed ? styles.completed : ''}`}>
      <div className={styles.content}>
        <Checkbox
          checked={task.completed}
          onChange={() => onToggle(task.id)}
        />
        <span className={styles.text}>
          {task.text} <small className={styles.category}>({category})</small>
        </span>
      </div>
      <div className={styles.actions}>
        <Button
          variant="secondary"
          onClick={() => setIsEditing(true)}
          className={styles.editButton}
        >
          Редактировать
        </Button>
        <Button
          variant="danger"
          onClick={() => onDelete(task.id)}
          className={styles.deleteButton}
        >
          Удалить
        </Button>
      </div>
    </div>
  );
};

export default TaskItem;
