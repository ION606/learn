const app = require('express')();
app.get('/', (req, res) => {
    res.json({ message: "UWU" })
});
const port = process.env.PORT || 3000;
app.listen(port, () => console.log(`app listening on port ${port}`));