// src/components/common/Input/Input.jsx

import styles from './Input.module.css';

const Input = ({ value, onChange, placeholder, type = 'text', className = '' }) => {
  return (
    <input
      className={`${styles.input} ${className}`}
      value={value}
      onChange={onChange}
      placeholder={placeholder}
      type={type}
    />
  );
};

export default Input;
