const questions = {
  aplusb: "A + B",
  calculus_wtf: "Calculus WTF",
  cancel_1112: "ยกเลิก 1112",
  nikkori_cafe: "จอมเวทแห่งคาเฟ่รอยยิ้ม (เวอร์ชั่นง่าย)",
  wtf: "WTF",
};

const iframe = document.querySelector(".pdf-viewer > iframe");
const qToken = window.location.search.split("=");
const question = qToken[1];

if (qToken.length >= 2) {
  if (questions[question]) {
    iframe.src = `./src/${question}.pdf`;
  } else {
    document.querySelector(".not-found").className += " activate";
  }
}

// * Default
iframe.src ||= "./src/aplusb.pdf";

document.querySelector(".pdf-viewer").className += " loaded";

const ul = document.querySelector(".problems-list");

for (const [short, full] of Object.entries(questions)) {
  const li = document.createElement("li");
  li.innerHTML = `<a href="?=${short}">${short} | ${full}</a>`;
  ul.appendChild(li);
}
