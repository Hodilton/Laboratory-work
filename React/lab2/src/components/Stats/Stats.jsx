// src/components/Stats/Stats.jsx

import styles from './Stats.module.css';

const Stats = ({ tasks }) => {
  const total = tasks.length;
  const completed = tasks.filter(t => t.completed).length;
  const progress = total === 0 ? 0 : Math.round((completed / total) * 100);

  return (
    <div className={styles.statsContainer}>
      <h3 className={styles.title}>Статистика</h3>
      <p>Всего задач: {total}</p>
      <p>Выполнено: {completed} ({progress}%)</p>
      <div className={styles.progressContainer}>
        <div 
          className={styles.progressBar}
          style={{ width: `${progress}%` }}
        ></div>
      </div>
    </div>
  );
};

export default Stats;
