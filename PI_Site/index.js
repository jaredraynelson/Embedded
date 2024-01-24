import express from "express";
import { spawn } from "child_process";
import { dirname } from "path";
import { fileURLToPath } from "url";

const app = express();
const port = 3000;
const __dirname = dirname(fileURLToPath(import.meta.url));
let pyData = '';




function RunPythonScriptForLightStatus(sName) {

  /*  THE PROMISE STATEMENT ALLOWS THE PROGRAM TO EXECUTE THIS OPERATION
      BEFORE JUMPING TO THE NEXT LINE OF CODE. (WORKS WITH ASYNC) SEE THE 
      app.get() TO VIEW THE ASYNC FUNCTION BELOW  */
  return new Promise((resolve, reject) => {
    const pyScriptPath = __dirname + sName;
    const spawnProcess = spawn('python', [pyScriptPath]);
    let pyOutput = '';
  
    spawnProcess.stdout.on('data', (data) => {
      pyOutput += data.toString();
    });

    spawnProcess.on('close', (code) => {
      // ... existing code

      if (code === 0) {
      pyData = JSON.parse(pyOutput);
      let msg = "";
      if (pyData['status'] === 'on') {
      // SEND BACK TO THE INDEX.EJS 'TURN OFF'
        msg += 'Turn Off Light'
      } else if (pyData['status'] === 'off') {
      // SEND BACK TO THE INDEX.EJS 'TURN ON'
        msg += 'Turn On Light'
      } else {
        msg+= 'Something went wrong. :/';
        
      }
      // SENDING THE PROMISE (SUCCESSFUL RETURN)
      resolve(msg);
      } else {
      // REJECTING THE PROMISE (UNSUCCESSFUL RETURN)
        reject(new Error('Python script failed with exit code: ' + code));
      }
    });
  }); 
}

app.get('/', async (req, res) => {
  try {
    const msg = await RunPythonScriptForLightStatus('/get-light-status.py');
    res.render('index.ejs', { message: msg });
  } catch (error) {
    console.error('Error:', error);
    // Handle the error appropriately, e.g., send an error response
  }

});


app.get('/toggle', async (req, res) => {
  try {
    const msg = await RunPythonScriptForLightStatus('/toggle-light.py');
    res.render('index.ejs', {message: msg});

  } catch (error) {
    console.error('Error:', error);
  }
  
});

app.listen(port, () => {
  console.log(`Server on the Pi is up\'in runnin\' on ${port}`);
});