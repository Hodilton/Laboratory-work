const Pool = require('pg').Pool
const pool = new Pool({
  user: 'barsuk',
  host: 'localhost',
  database: 'my_database',
  password: 'qwerty',
  port: 5432,
});

const getMerchants = () => {
    return new Promise(function(resolve, reject) {
      pool.query('SELECT * FROM merchants ORDER BY id ASC', (error, results) => {
        if (error) {
          reject(error)
        }
        resolve(results.rows);
      }) }) 
}

const createMerchant = (body) => {
    return new Promise(function(resolve, reject) {
    const { name, email } = body
    pool.query('INSERT INTO merchants (name, email) VALUES ($1, $2) RETURNING *', [name, email], (error, results) => {
        if (error) {
        reject(error)
        }
        resolve(`A new merchant has been added: ${results.rows[0]}`)
    })
    })
}

const deleteMerchant = () => {
    return new Promise(function(resolve, reject) {
    const id = parseInt(request.params.id)
    pool.query('DELETE FROM merchants WHERE id = $1', [id], (error, results) => {
        if (error) {
        reject(error)
        }
        resolve(`Merchant deleted with ID: ${id}`)
    })
    })
}

const updateMerchant = (id, name, email) => {
    return new Promise(function(resolve, reject) {
        pool.query('UPDATE merchants SET name = $1, email = $2 WHERE id = $3 RETURNING *', [name, email, id], (error, results) => {
            if (error) {
                reject(error);
            }
            resolve(`Продавец обновлен с ID: ${id}`);
        });
    });
};

module.exports = {
    getMerchants,
    createMerchant,
    deleteMerchant,
    updateMerchant,
  }
