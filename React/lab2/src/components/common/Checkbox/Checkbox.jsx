// src/components/common/Checkbox/Checkbox.jsx

import styles from './Checkbox.module.css';

const Checkbox = ({ checked, onChange, className = '' }) => {
  return (
    <input
      type="checkbox"
      className={`${styles.checkbox} ${className}`}
      checked={checked}
      onChange={onChange}
    />
  );
};

export default Checkbox;
