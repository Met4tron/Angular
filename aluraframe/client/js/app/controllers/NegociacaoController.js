// aluraframe/client/js/app/controllers/NegociacaoController.js

class NegociacaoController {

    constructor() {

        let $ = document.querySelector.bind(document);
        this._inputData = $('#data');
        this._inputQuantidade = $('#quantidade');
        this._inputValor = $('#valor');
        this._listaNegociacoes = new ListaNegociacoes(); // Nova Lista de Negociação
    }

    adiciona(event) {

        event.preventDefault();

        let negociacao = this._criaNegociacao();

       this._listaNegociacoes.adiciona(negociacao);
       console.log(this._listaNegociacoes.negociacoes);

       this._limpa();

    }

    _criaNegociacao(){
        return new Negociacao(
            DateHelper.textoData(this._inputData.value),
            this._inputQuantidade.value,
            this._inputValor.value
        );
    }

    _limpa() {

        this._inputQuantidade.value = 1;
        this._inputValor.value = 0,0;
        this._inputData.value = '';
        this._inputData.focus();
    }


}