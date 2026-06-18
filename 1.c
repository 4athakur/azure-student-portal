<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>Student Information Collection Portal - IIIT Bhopal</title>
  
  <link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
  <link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700&family=Poppins:wght@400;500;600;700&display=swap" rel="stylesheet">

  <style>
    :root {
      --primary-color: #0b3c5d;
      --primary-dark: #06273f;
      --secondary-color: #328cc1;
      --accent-color: #d9b310;
      --bg-gradient: linear-gradient(135deg, #f4f7f6 0%, #e9eff5 100%);
      --text-main: #1d2731;
      --text-muted: #576574;
      --card-bg: rgba(255, 255, 255, 0.95);
      --success-color: #1b5e20;
      --success-bg: #e8f5e9;
      --error-color: #b71c1c;
      --error-bg: #ffebee;
      --border-color: #cfd8dc;
      --readonly-bg: #f8fafc;
    }

    * { 
      margin: 0; 
      padding: 0; 
      box-sizing: border-box; 
      font-family: 'Inter', sans-serif; 
    }

    body {
      min-height: 100vh;
      background: var(--bg-gradient);
      color: var(--text-main);
      display: flex;
      flex-direction: column;
      justify-content: space-between;
      align-items: center;
      overflow-x: hidden;
      padding: 20px;
    }

    /* Top Institutional Header Bar */
    .uni-header {
      width: 100%;
      max-width: 750px;
      text-align: center;
      margin-bottom: 25px;
      border-bottom: 3px solid var(--primary-color);
      padding-bottom: 15px;
    }

    .uni-logo-placeholder {
      font-family: 'Poppins', sans-serif;
      font-size: 26px;
      font-weight: 700;
      color: var(--primary-color);
      letter-spacing: 1.5px;
      margin-bottom: 5px;
      text-transform: uppercase;
    }

    .uni-title {
      font-size: 20px;
      font-weight: 600;
      color: var(--text-main);
      margin-bottom: 4px;
    }

    .uni-subtitle {
      font-size: 14px;
      color: var(--secondary-color);
      font-weight: 500;
      text-transform: uppercase;
      letter-spacing: 0.5px;
    }

    /* Main Component Container */
    .container {
      width: 100%;
      max-width: 750px;
      background: var(--card-bg);
      border: 1px solid rgba(225, 230, 235, 0.8);
      border-radius: 12px;
      padding: 40px;
      box-shadow: 0 15px 35px rgba(11, 60, 93, 0.08), 0 5px 15px rgba(0, 0, 0, 0.04);
      animation: slideUp 0.6s cubic-bezier(0.16, 1, 0.3, 1);
    }

    @keyframes slideUp { 
      from { opacity: 0; transform: translateY(24px); } 
      to { opacity: 1; transform: translateY(0); } 
    }

    /* Official Academic Instructions Notice Box */
    .notice-box {
      background-color: #f0f7ff;
      border-left: 4px solid var(--secondary-color);
      padding: 15px 20px;
      border-radius: 4px;
      margin-bottom: 30px;
      font-size: 13.5px;
      line-height: 1.6;
      color: #1e40af;
      display: flex;
      align-items: flex-start;
    }

    .notice-box::before {
      content: "ℹ";
      font-weight: bold;
      margin-right: 12px;
      font-size: 16px;
    }

    /* Section Subheadings */
    .section-title {
      grid-column: span 2;
      font-size: 15px;
      font-weight: 700;
      color: var(--primary-color);
      text-transform: uppercase;
      letter-spacing: 0.5px;
      margin-top: 10px;
      border-bottom: 1px dashed var(--border-color);
      padding-bottom: 6px;
    }

    /* Professional Multi-Column Grid Form */
    .form-grid {
      display: grid;
      grid-template-columns: 1fr 1fr;
      gap: 20px 24px;
    }

    .input-group { 
      position: relative; 
    }

    /* Spread standard width fields across desktop screens where appropriate */
    .full-width {
      grid-column: span 2;
    }

    .input-group label { 
      color: var(--primary-dark); 
      font-size: 13px; 
      margin-bottom: 6px; 
      display: block; 
      font-weight: 600;
      letter-spacing: 0.3px;
    }

    .input-group input, .input-group select {
      width: 100%; 
      padding: 12px 16px; 
      outline: none; 
      border-radius: 6px;
      background: #ffffff; 
      color: var(--text-main); 
      font-size: 14.5px;
      transition: all 0.2s ease-in-out; 
      border: 1px solid var(--border-color);
    }

    .input-group input:focus, .input-group select:focus {
      border-color: var(--secondary-color); 
      box-shadow: 0 0 0 3px rgba(50, 140, 193, 0.15);
      background-color: #fff;
    }

    /* Accessible Visual Validation States */
    .input-group input:invalid:not(:placeholder-shown) {
      border-color: var(--error-color);
    }

    .submit-btn {
      grid-column: span 2;
      width: 100%; 
      padding: 14px; 
      border: none; 
      border-radius: 6px;
      background: var(--primary-color); 
      color: white;
      font-size: 15px; 
      font-weight: 600; 
      letter-spacing: 0.5px;
      cursor: pointer; 
      transition: background 0.2s ease, transform 0.1s ease;
      margin-top: 15px;
      box-shadow: 0 4px 12px rgba(11, 60, 93, 0.15);
    }

    .submit-btn:hover { 
      background: var(--primary-dark); 
    }

    .submit-btn:active {
      transform: scale(0.99);
    }

    .submit-btn:disabled {
      background: #a0aec0;
      cursor: not-allowed;
      box-shadow: none;
    }

    /* Status Notifications Box */
    .status { 
      margin-top: 25px; 
      padding: 14px;
      border-radius: 6px;
      text-align: center; 
      font-size: 14px; 
      font-weight: 500;
      min-height: 20px;
      display: none;
      animation: fadeIn 0.3s ease;
    }

    @keyframes fadeIn { from { opacity: 0; } to { opacity: 1; } }

    .status.loading {
      display: block;
      background: #f8fafc;
      color: #475569;
      border: 1px solid #e2e8f0;
    }

    .status.success {
      display: block;
      background: var(--success-bg);
      color: var(--success-color);
      border: 1px solid rgba(27, 94, 32, 0.2);
    }

    .status.error {
      display: block;
      background: var(--error-bg);
      color: var(--error-color);
      border: 1px solid rgba(183, 28, 28, 0.2);
    }

    /* CSS Loader Animation */
    .spinner {
      display: inline-block;
      width: 16px;
      height: 16px;
      border: 2.5px solid rgba(71, 85, 105, 0.2);
      border-radius: 50%;
      border-top-color: #475569;
      animation: spin 0.8s linear infinite;
      margin-right: 10px;
      vertical-align: -2px;
    }

    @keyframes spin {
      to { transform: rotate(360deg); }
    }

    /* Portal Footer */
    .footer { 
      margin-top: 40px; 
      text-align: center; 
      color: var(--text-muted); 
      font-size: 12px; 
      letter-spacing: 0.3px;
      width: 100%;
    }

    /* High-Quality Responsiveness */
    @media (max-width: 640px) {
      .form-grid {
        grid-template-columns: 1fr;
        gap: 18px;
      }
      .full-width, .submit-btn, .section-title {
        grid-column: span 1;
      }
      .container {
        padding: 24px 20px;
      }
      .uni-header {
        margin-bottom: 15px;
      }
      .uni-logo-placeholder {
        font-size: 22px;
      }
      .uni-title {
        font-size: 17px;
      }
    }
  </style>
</head>
<body>

  <header class="uni-header">
    <div class="uni-logo-placeholder">IIIT Bhopal</div>
    <h1 class="uni-title">Student Information Collection Portal</h1>
    <p class="uni-subtitle">MCA Student Details Submission</p>
  </header>

  <main class="container">
    <div class="notice-box" role="note">
      Please submit your academic and profiles information below. Ensure all filled details match official institute records accurately.
    </div>

    <form id="studentForm" novalidate>
      <div class="form-grid">
        
        <h2 class="section-title">Student Profile Information</h2>

        <div class="input-group full-width">
          <label for="fullName">Full Name</label>
          <input type="text" id="fullName" placeholder="Enter your full name as per official records" required autocomplete="name" />
        </div>

        <div class="input-group">
          <label for="scholarNumber">Scholar Number</label>
          <input type="text" id="scholarNumber" placeholder="e.g. 211105001" required pattern="[A-Za-z0-9]+" title="Please enter your unique institutional scholar ID string" />
        </div>

        <div class="input-group">
          <label for="email">Email ID</label>
          <input type="email" id="email" placeholder="student@iiitbhopal.ac.in" required autocomplete="email" />
        </div>

        <div class="input-group">
          <label for="groupNumber">Group Number</label>
          <select id="groupNumber" required>
            <option value="" disabled selected>Select Group</option>
            <option value="Group 1">Group 1</option>
            <option value="Group 2">Group 2</option>
            <option value="Group 3">Group 3</option>
            <option value="Group 4">Group 4</option>
            <option value="Group 5">Group 5</option>
            <option value="Group 6">Group 6</option>
            <option value="Group 7">Group 7</option>
            <option value="Group 8">Group 8</option>
            <option value="Group 9">Group 9</option>
            <option value="Group 10">Group 10</option>
            <option value="Group 11">Group 11</option>
            <option value="Group 12">Group 12</option>
            <option value="Group 13">Group 13</option>
            <option value="Group 14">Group 14</option>
            <option value="Group 15">Group 15</option>
            <option value="Group 16">Group 16</option>
            <option value="Group 17">Group 17</option>
          </select>
        </div>

        <div class="input-group">
          <label for="areaOfInterest">Area of Interest</label>
          <input type="text" id="areaOfInterest" placeholder="e.g. Artificial Intelligence, Cyber Security, Data Science, Web Development, Cloud Computing" required />
        </div>

        <button class="submit-btn" type="submit" id="submitBtn">Submit Details</button>
      </div>
    </form>

    <div class="status" id="status" role="alert" aria-live="polite"></div>
  </main>

  <footer class="footer">
    &copy; 2026 Academic Records. All Rights Reserved.
    <br>
    <span style="font-size: 10px; opacity: 0.75; margin-top: 4px; display: inline-block;">Academic Data Management</span>
  </footer>

  <script>
    document.getElementById("studentForm").addEventListener("submit", async function(e){
      e.preventDefault();
      
      const form = this;
      const status = document.getElementById("status");
      const submitBtn = document.getElementById("submitBtn");

      // Baseline Verification check before allowing submissions
      if (!form.checkValidity()) {
        status.className = "status error";
        status.innerHTML = "❌ Please correct the highlighted errors and fill out all fields accurately before submitting.";
        form.reportValidity();
        return;
      }

      // Setting UI elements to Loading State
      status.className = "status loading";
      status.innerHTML = `<span class="spinner"></span> Processing and transmitting profile data...`;
      submitBtn.disabled = true;

      // Extract values matching the requested submission data payload
      const data = {
        fullName: document.getElementById("fullName").value.trim(),
        email: document.getElementById("email").value.trim(),
        scholarNumber: document.getElementById("scholarNumber").value.trim(),
        groupNumber: document.getElementById("groupNumber").value,
        areaOfInterest: document.getElementById("areaOfInterest").value.trim()
      };

      try {
        // App Script Endpoint Connection Remains Unchanged
        const scriptURL = "https://script.google.com/macros/s/AKfycby89QXg66ylK1l051Y6V6ItdsDpYf_n8LPIbd40gtGbB0VuRZ4hzyqCacf5ataioEsb/exec";

        await fetch(scriptURL, {
          method: "POST",
          mode: "no-cors", 
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify(data)
        });

        // Clear Form fields and post institutional Success Status
        status.className = "status success";
        status.innerHTML = "● Student details submitted successfully.";
        form.reset();

      } catch(error) {
        // Handle runtime/network issues seamlessly
        status.className = "status error";
        status.innerHTML = "❌ Unable to process your request at this time. Please try again later.";
        console.error("Submission Error Pipeline: ", error);
      } finally {
        // Reset functional availability to input button
        submitBtn.disabled = false;
      }
    });
  </script>
</body>
</html>
