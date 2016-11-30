class NegociacoesView extends View{

    constructor(elemento) {
        super(elemento);
    }

    template(model) {

            return `
            <table class="table table-hover table-bordered">
                <thead>
                    <tr>
                        <th>Data</th>
                        <th>Quantidade</th>
                        <th>Valor</th>
                        <th>Volume</th>
                    </tr>
                </thead>
                <tbody>
                    ${model.negociacoes.map(n => `
                         
                            <tr>
                                <td>${DateHelper.dataTexto(n.data)}</td>
                                <td>${n.quantidade}</td>
                                <td>${n.valor}</td>
                                <td>${n.volume}</td>
                            </tr>
                            
                    `).join('')
                }
                </tbody>
                <tfoot>
                    <td colspan="3"></td>
                    <td>
                        ${model.negociacoes.reduce((total, n) => total + n.volume, 0.0)}
                    </td>
                </tfoot>
            </table>    
        `;
    }
}