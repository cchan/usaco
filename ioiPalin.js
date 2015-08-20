function lcs(s1, s2){
	if(s1.length == 0 || s2.length == 0)
		return "";
	else if(s1[0] == s2[0])
		return s1[0] + lcs(s1.slice(1),s2.slice(1));
	else
		return longest(lcs(s1.slice(1),s2),lcs(s1,s2.slice(1)));
}
function longest(s1, s2){
	if(s1.length > s2.length)
		return s1;
	else
		return s2;
}
console.log(lcs("wheninthecourseofhumaneventsitbecomesnecessary","foronepeopletodissolvethepoliticalbandswhichhave"));