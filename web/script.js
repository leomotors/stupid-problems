const questions = {
  /// <Questions />
};

const iframe = document.querySelector(".pdf-viewer > iframe");
const qToken = window.location.search.split("=");
const question = qToken[1];

if (qToken.length >= 2) {
  if (questions[question]) {
    iframe.src = `./pdf/${question}.pdf`;
  } else {
    document.querySelector(".not-found").className += " activate";
  }
}

// * Default
iframe.src ||= "./pdf/aplusb.pdf";

document.querySelector(".pdf-viewer").className += " loaded";

const ul = document.querySelector(".problems-list");

for (const [short, full] of Object.entries(questions)) {
  const li = document.createElement("li");
  li.innerHTML = `<a href="?=${short}">${short} | ${full}</a>`;
  ul.appendChild(li);
}
