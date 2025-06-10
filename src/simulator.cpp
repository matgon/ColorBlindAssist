#include "cba/simulator.hpp"
#include <opencv2/opencv.hpp>

namespace ColorBlindAssist {
    Color Simulator::simulate(Color color, DaltonismType type) {
        Color ret(0,0,0);
        int r{0}, g{0}, b{0};
        switch (type)
        {
            case DaltonismType::Protanopia:
            // Protanopia	[[0.5667, 0.4333, 0], [0.5583, 0.4417, 0], [0, 0.2417, 0.7583]]
                r = static_cast<int>(color.get_r() * 0.5667 + color.get_g() * 0.4333);
                g = static_cast<int>(color.get_r() * 0.5583 + color.get_g() * 0.4417);
                b = static_cast<int>(color.get_g() * 0.2417 + color.get_b() * 0.7583);
                break;
            case DaltonismType::Deuteranopia:
            // Deuteranopia	[[0.625, 0.375, 0], [0.7, 0.3, 0], [0, 0.3, 0.7]]
                r = static_cast<int>(color.get_r() * 0.625 + color.get_g() * 0.375);
                g = static_cast<int>(color.get_r() * 0.7 + color.get_g() * 0.3);
                b = static_cast<int>(color.get_g() * 0.3 + color.get_b() * 0.7);
                break;
            case DaltonismType::Tritanopia:
            // Tritanopia	[[0.95, 0.05, 0], [0, 0.4333, 0.5667], [0, 0.475, 0.525]]
                r = static_cast<int>(color.get_r() * 0.95 + color.get_g() * 0.05);
                g = static_cast<int>(color.get_g() * 0.4333 + color.get_b() * 0.5667);
                b = static_cast<int>(color.get_g() * 0.475 + color.get_b() * 0.525);
                break;
            default:
                break;
        }
        ret.set_r(r);
        ret.set_g(g);
        ret.set_b(b);
        return ret;
    }

    void Simulator::simularDaltonismo(const std::string& ruta, DaltonismType tipo) {
        cv::Mat imagen = cv::imread(ruta, cv::IMREAD_COLOR);
        cv::Mat imagenRGB;
        cv::cvtColor(imagen, imagenRGB, cv::COLOR_RGB2BGR);
        if (imagen.empty()) {
            std::cerr << "No se pudo cargar la imagen." << std::endl;
            return;
        }
        
        cv::Mat resultado = imagenRGB.clone();
        cv::Mat resultadoBGR;

        Simulator simulador;

        for (int y = 0; y < imagen.rows; ++y) {
            for (int x = 0; x < imagen.cols; ++x) {
                cv::Vec3b pixel = imagen.at<cv::Vec3b>(y, x);
                Color color(pixel[0], pixel[1], pixel[2]);
                Color simulado = simulador.simulate(color, tipo);
                resultado.at<cv::Vec3b>(y, x) = cv::Vec3b(
                    std::clamp(simulado.get_b(), 0, 255),
                    std::clamp(simulado.get_g(), 0, 255),
                    std::clamp(simulado.get_r(), 0, 255)
                );
            }
        }
        cv::cvtColor(resultado, resultadoBGR, cv::COLOR_RGB2BGR);
        cv::imshow("Imagen original", imagen);
        cv::imshow("Simulacion de Daltonismo", resultadoBGR);
        cv::waitKey(0);
        cv::imwrite("imagen_simulada.png", resultadoBGR);
    }


}
