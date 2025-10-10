// src/components/TaskList/TaskList.jsx

import TaskItem from '../TaskItem/TaskItem.jsx';
import styles from './TaskList.module.css';

const TaskList = ({ tasks, onToggle, onDelete, onEdit }) => {
  if (tasks.length === 0) {
    return <p className={styles.emptyMessage}>Нет задач</p>;
  }

  return (
    <div className={styles.listContainer}>
      {tasks.map(task => (
        <TaskItem
          key={task.id}
          task={task}
          onToggle={onToggle}
          onDelete={onDelete}
          onEdit={onEdit}
        />
      ))}
    </div>
  );
};

export default TaskList;
