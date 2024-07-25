
class Agenda:
    def __init__(self):
        self.qtd_eventos = 0
        pass
    
    def add_Eventos(self):
        self.qtd_eventos += 1
    
    def get_Eventos(self):
        if self.qtd_eventos >= 1:
            print('Final dos 100m: 2024-07-24 10:00 a 2024-07-24 11:00')
        else:
            print('Nenhum evento agendado.')
    
    def sair(self):
        return 0