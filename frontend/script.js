/* Vehicle rule control */

const vehicleSelect = document.getElementById("vehicle");
const seatbeltSelect = document.getElementById("seatbelt");
const helmetSelect = document.getElementById("helmet");

let cases = [];

function updateVehicleRules() {

    const vehicle = vehicleSelect.value;

    if (vehicle === "CAR") {

        seatbeltSelect.disabled = false;
        helmetSelect.disabled = true;

    }

    else if (vehicle === "BIKE") {

        seatbeltSelect.disabled = true;
        helmetSelect.disabled = false;

    }

    else if (vehicle === "TRUCK") {

        seatbeltSelect.disabled = true;
        helmetSelect.disabled = true;

    }

}

/* vehicle change হলে rule update */

vehicleSelect.addEventListener("change", updateVehicleRules);

/* page load হলে run হবে */

updateVehicleRules();



/* Add Case button */

document.getElementById("addCase").addEventListener("click", function () {

    const vehicle = document.getElementById("vehicle").value;
    const plate = document.getElementById("plate").value;
    const speed = document.getElementById("speed").value;
    const limit = document.getElementById("limit").value;
    const signal = document.getElementById("signal").value;
    const seatbelt = document.getElementById("seatbelt").value;
    const helmet = document.getElementById("helmet").value;
    const zone = document.getElementById("zone").value;
    const time = document.getElementById("time").value;
    const alcohol = document.getElementById("alcohol").value;

    let caseInput = `CASE {
VEHICLE ${vehicle}
PLATE ${plate}
SPEED ${speed}
LIMIT ${limit}
SIGNAL ${signal}
`;

    if (vehicle === "CAR") {
        caseInput += `SEATBELT ${seatbelt}\n`;
    }

    if (vehicle === "BIKE") {
        caseInput += `HELMET ${helmet}\n`;
    }

    if (zone !== "NORMAL") {
        caseInput += `ZONE ${zone}\n`;
    }

    caseInput += `TIME ${time}
ALCOHOL ${alcohol}
}
`;

    cases.push(caseInput);

    /* Added cases preview */

    document.getElementById("caseList").textContent = cases.join("\n");

});



/* Form submit */

document.getElementById("trafficForm").addEventListener("submit", async function (e) {

    e.preventDefault();

    /* সব case একসাথে backend এ যাবে */

    const allCases = cases.join("\n");

    const response = await fetch("/analyze", {

        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify({ data: allCases })

    });

    const result = await response.text();

    /* result save */

    localStorage.setItem("traffic_report", result);

    /* result page */

    window.location.href = "result.html";

});