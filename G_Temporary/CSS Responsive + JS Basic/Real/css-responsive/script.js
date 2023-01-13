const toggleBtn = document.querySelector(".toggle-button");
const navbarLinks = document.querySelector(".navbar-links");

toggleBtn.addEventListener("click", () => {
	navbarLinks.classList.toggle("navbar-links-mobile");
});
