/* function padTo2Digits(num) {
    return num.toString().padStart(2, '0');
  }

  function formatDate(date) {
    return [
      padTo2Digits(date.getDate()),
      padTo2Digits(date.getMonth() + 1),
      date.getFullYear(),
    ].join('/');
  } */
// Count days until next birthday
function convertToDate(dateString) {

    let d = dateString.split("/");
    let dat = new Date(d[2] + '/' + d[1] + '/' + d[0]);
    return dat;
}
function daysTilBday(bdayString) {
    let today = new Date();
    let myBday = convertToDate(bdayString);
    let age = today.getFullYear() - myBday.getFullYear();
    let upcomingBday = new Date(today.getFullYear(), myBday.getMonth(), myBday.getDate());

    if (today > upcomingBday) {
        upcomingBday.setFullYear(today.getFullYear() + 1);
    }
    let oneDay = 24 * 60 * 60 * 1000;
    let daysLeft = Math.ceil((upcomingBday.getTime() - today.getTime()) / (oneDay));
    console.log(`In ${daysLeft} day(s), you will be ${age + 1}`);
}
console.log(daysTilBday('31/08/1995'));