const express = require('express')
const cors = require('cors');

const app = express()
const port = 3001

const merchant_model = require('./models/merchant_model')

app.use(cors({
    origin: 'http://localhost:3000',
    methods: ['GET', 'POST', 'PUT', 'DELETE', 'OPTIONS'],
    allowedHeaders: ['Content-Type'],
}));

app.use(express.json())

app.use(function (req, res, next) {
    res.setHeader('Access-Control-Allow-Origin', 'http://localhost:3000');
    res.setHeader('Access-Control-Allow-Methods', 'GET,POST,PUT,DELETE,OPTIONS');
    res.setHeader('Access-Control-Allow-Headers', 'Content-Type, Access-Control-Allow-Headers');
    next();
});

app.get('/', (req, res) => {
    merchant_model.getMerchants()
        .then(response => {
            res.status(200).send(response);
        })
        .catch(error => {
            res.status(500).send(error);
        })
})

app.post('/merchants', (req, res) => {
    merchant_model.createMerchant(req.body)
        .then(response => {
            res.status(200).send(response);
        })
        .catch(error => {
            res.status(500).send(error);
        })
})

app.delete('/merchants/:id', (req, res) => {

    merchant_model.deleteMerchant(req.params.id)
        .then(response => {
            res.status(200).send(response);
        })
        .catch(error => {
            res.status(500).send(error);
        })
})

app.put('/edit-merchants/:id', (req, res) => {

    const id = req.params.id;
    const { name, email } = req.body;

    merchant_model.updateMerchant(id, name, email)
        .then(response => {
            res.status(200).json({ message: response });
        })
        .catch(error => {
            res.status(500).json({ error: error.message });
        });
});

app.listen(port, () => {
    console.log(`App running on port ${port}.`)
})
