highRiskMessage = "Hello, We are writing to notify you that someone at LASA has tested positive for COVID-19. We have been alerted that the individual diagnosed with COVID-19 was in close proximity to your child and based on your child's proximity to this individual, we have determined them to be at a high risk for exposure. As such, we ask you to monitor your child's symptoms closely and review the LASA and AustinISD's COVID protocols which can be found at this website: https://final-project-web-display.nkamble.repl.co/protocol.html";

mediumRiskMessage = "Hello, We are writing to notify you that someone at LASA has tested positive for COVID-19. We have been alerted that the individual diagnosed with COVID-19 was in close proximity to your child and based on your child's proximity to this individual, we have determined them to be at a medium risk for exposure. As such, we ask you to monitor your child's symptoms closely and review the LASA and AustinISD's COVID protocols which can be found at this website: https://final-project-web-display.nkamble.repl.co/protocol.html";

lowRiskMessage = "Hello, We are writing to notify you that someone at LASA has tested positive for COVID-19. We have been alerted that the individual diagnosed with COVID-19 was in close proximity to your child and based on your child's proximity to this individual, we have determined them to be at a low risk for exposure. As such, we ask you to monitor your child's symptoms closely and review the LASA and AustinISD's COVID protocols which can be found at this website: https://final-project-web-display.nkamble.repl.co/protocol.html";

messages = [highRiskMessage, mediumRiskMessage, lowRiskMessage];


function emailMessage(risk){
  if(risk == "High Risk"){
    return messages[0];
  }
  else if(risk == "Medium Risk"){
    return messages[1];
  }
  else if(risk == "Low Risk"){
    return messages[2];
  }
}

function sendEMail(email, risk){
  subject = "COVID Exposure Notification";
  body = emailMessage(risk);
  console.log("To: " + email);
  console.log("Subject: " + subject)
  console.log("Message: " + body)
  window.open('mailto:email?subject=subject&body=body');
}

sendEMail("xyz@austinisd.org", "Low Risk");

