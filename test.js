    document.getElementById("submit1").onclick = check
    window.document.StDaForm.zgpj.value = "无"
for ( var i = 0; i < document.StDaForm.elements.length; i++) {
    if (document.StDaForm.elements[i].type == 'radio') {
        if(document.StDaForm.elements[i].id%2==1){
        document.StDaForm.elements[i].checked=check
    }
    }
}
document.getElementById("submit1").onclick()