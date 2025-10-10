// src/App.jsx

import { useState } from 'react';
import { useTaskContext } from './contexts/TaskContext.jsx';
import TaskForm from './components/TaskForm/TaskForm.jsx';
import CategoryFilter from './components/CategoryFilter/CategoryFilter.jsx';
import TaskList from './components/TaskList/TaskList.jsx';
import Stats from './components/Stats/Stats.jsx';

function App() {
  const { tasks, addTask, deleteTask, toggleTask, editTask, sortTasksByDate } = useTaskContext();
  const [selectedCategory, setSelectedCategory] = useState('all');


  const filteredTasks = selectedCategory === 'all'
    ? tasks
    : tasks.filter(task => task.categoryId === selectedCategory);


  const sortedTasks = sortTasksByDate(filteredTasks);

  return (
    <div className="app">
      <Stats tasks={tasks} />
      <CategoryFilter
        selectedCategory={selectedCategory}
        onSelectCategory={setSelectedCategory}
      />
      <TaskForm onAddTask={addTask} />
      <TaskList
        tasks={sortedTasks}
        onToggle={toggleTask}
        onDelete={deleteTask}
        onEdit={editTask}
      />
    </div>
  );
}

export default App;
