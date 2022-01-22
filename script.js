const questions = [
  "aplusb",
  "calculus_wtf",
  "cancel_1112",
  "nikkori_cafe",
  "wtf",
];

const iframe = document.querySelector("iframe");
const qToken = window.location.search.split("=");
const question = window.location.search.split("=")[1];

if (qToken.length >= 2) {
  if (questions.indexOf(question) === -1) {
    document.querySelector(".not-found").className += " activate";
  } else {
    iframe.src = `./${question}.pdf`;
  }
}

const ul = document.querySelector(".problems-list");

questions.forEach((question) => {
  const li = document.createElement("li");
  li.innerHTML = `<a href="./index.html?q=${question}">${question}</a>`;
  ul.appendChild(li);
});
