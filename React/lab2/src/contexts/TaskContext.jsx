// src/contexts/TaskContext.js

import { createContext, useContext } from 'react';
import { useTasks } from '../hooks/useTasks';

const TaskContext = createContext();

export const TaskProvider = ({ children }) => {
  const taskMethods = useTasks();
  return (
    <TaskContext.Provider value={taskMethods}>
      {children}
    </TaskContext.Provider>
  );
};

export const useTaskContext = () => {
  const context = useContext(TaskContext);
  if (!context) {
    throw new Error('useTaskContext must be used within TaskProvider');
  }
  return context;
};
