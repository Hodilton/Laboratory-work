// src/components/common/Button/Button.jsx

import styles from './Button.module.css';

const Button = ({ children, onClick, variant = 'primary', type = 'button', className = '' }) => {
  return (
    <button 
      className={`${styles.button} ${styles[variant]} ${className}`}
      onClick={onClick} 
      type={type}
    >
      {children}
    </button>
  );
};

export default Button;
