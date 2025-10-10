// src/components/CategoryFilter/CategoryFilter.jsx

import { CATEGORIES } from '../../utils/constants.js';
import Button from '../common/Button/Button.jsx';
import styles from './CategoryFilter.module.css';

const CategoryFilter = ({ selectedCategory, onSelectCategory }) => {
  const categoriesWithAll = [{ id: 'all', name: 'Все' }, ...CATEGORIES];

  return (
    <div className={styles.container}>
      <h3 className={styles.title}>Категория:</h3>
      <div className={styles.buttonsContainer}>
        {categoriesWithAll.map(cat => (
          <Button
            key={cat.id}
            variant={selectedCategory === cat.id ? 'primary' : 'secondary'}
            onClick={() => onSelectCategory(cat.id)}
          >
            {cat.name}
          </Button>
        ))}
      </div>
    </div>
  );
};

export default CategoryFilter;
