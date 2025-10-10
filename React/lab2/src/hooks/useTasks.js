// src/hooks/useTasks.js

import { useState, useEffect } from 'react';
import { CATEGORIES } from '../utils/constants';

const TASKS_STORAGE_KEY = 'tasks';

const loadTasksFromStorage = () => {
  try {
    const stored = localStorage.getItem(TASKS_STORAGE_KEY);
    if (stored) {
      return JSON.parse(stored);
    }
  } catch (error) {
    console.error('Failed to load tasks from localStorage', error);
  }
  return [];
};

const saveTasksToStorage = (tasks) => {
  try {
    localStorage.setItem(TASKS_STORAGE_KEY, JSON.stringify(tasks));
  } catch (error) {
    console.error('Failed to save tasks to localStorage', error);
  }
};

export const useTasks = () => {
  const [tasks, setTasks] = useState(() => {
    const saved = loadTasksFromStorage();
    return saved.length > 0 ? saved : [
      {
        id: '1',
        text: 'Сделать домашку',
        categoryId: 'work',
        completed: false,
        createdAt: new Date().toISOString(),
      },
    ];
  });

  useEffect(() => {
    saveTasksToStorage(tasks);
  }, [tasks]);

  const addTask = (text, categoryId) => {
    const newTask = {
      id: Date.now().toString(),
      text: text.trim(),
      categoryId,
      completed: false,
      createdAt: new Date().toISOString(),
    };
    setTasks(prev => [...prev, newTask]);
  };

  const deleteTask = (id) => {
    setTasks(prev => prev.filter(task => task.id !== id));
  };

  const toggleTask = (id) => {
    setTasks(prev =>
      prev.map(task =>
        task.id === id ? { ...task, completed: !task.completed } : task
      )
    );
  };

  const editTask = (id, newText, newCategoryId) => {
    setTasks(prev =>
      prev.map(task =>
        task.id === id
          ? { ...task, text: newText.trim(), categoryId: newCategoryId }
          : task
      )
    );
  };

  const sortTasksByDate = (tasksArray) => {
    return [...tasksArray].sort((a, b) => new Date(b.createdAt) - new Date(a.createdAt));
  };

  return {
    tasks,
    addTask,
    deleteTask,
    toggleTask,
    editTask,
    sortTasksByDate,
  };
};
