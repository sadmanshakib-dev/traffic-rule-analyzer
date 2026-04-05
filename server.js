const express = require("express");
const fs = require("fs");
const { exec } = require("child_process");
const path = require("path");

const app = express();

app.use(express.json());
app.use(express.static("frontend"));

app.post("/analyze", (req, res) => {

    const inputData = req.body.data;

    /* input.txt create */

    fs.writeFileSync(path.join(__dirname, "backend", "input.txt"), inputData);

    /* traffic.exe run */

    exec("cd backend && traffic.exe input.txt", (error, stdout, stderr) => {

        if (error) {
            console.log("Execution Error:", error);
            return res.send("Error running analyzer");
        }

        /* report read */

        const report = fs.readFileSync(path.join(__dirname, "backend", "report.txt"), "utf8");

        res.send(report);

    });

});

app.listen(3000, () => {
    console.log("Server running on http://localhost:3000");
});