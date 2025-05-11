import React, {useState, useEffect} from 'react';
import './App.css';

function App() {
  const [merchants, setMerchants] = useState(false);
  useEffect(() => {
    getMerchant();
  }, []);

  function getMerchant() {
    fetch('http://localhost:3001')
        .then(response => response.json())
        .then(data => {
          setMerchants(data);
        });
  }

  function createMerchant() {
    let name = prompt('Enter merchant name:');
    let email = prompt('Enter merchant email:');
    
    fetch('http://localhost:3001/merchants', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({name, email}),
    })
        .then(response => {
          return response.text();
        })
        .then(data => {
          alert(data);
          getMerchant();
        });
  }
    function deleteMerchant() {
        let id = prompt('Enter merchant id:');
        fetch(`http://localhost:3001/merchants/${id}`, {
            method: 'DELETE',
        }).then(response => {
            return response.text();
        }).then(data => {
                alert(data);
                getMerchant();
        });
    }

   return (
   <div>
        <h1>Merchants</h1>
        <ul>
            {merchants && merchants.map((merchant) => (
                <li key={merchant.id}>{merchant.name} ({merchant.email})</li>
            ))}
        </ul>
        <button onClick={createMerchant}>Add merchant</button>
        <button onClick={deleteMerchant}>Delete merchant</button>
    </div>
  );
}

export default App;
