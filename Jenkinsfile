pipeline {
	agent any

	options {
		buildDiscarder(logRotator(numToKeepStr: '10'))
	}

	parameters {
		booleanParam name: 'RUN_ANALYSIS', defaultValue: true, description: 'Run Static Code Analysis?'
	}

	stages {
        stage('Build') {
            when {
                environment name: 'RUN_ANALYSIS', value: 'false'
            }
            steps {
		sh "make"
            }
        }

        stage('BuildWithCoderrect') {
            when {
                environment name: 'RUN_ANALYSIS', value: 'true'
            }
            steps {
                sh "make clean"
                sh "coderrect make"
            }
        }

        stage('Analyse') {
            when {
                environment name: 'RUN_ANALYSIS', value: 'true'
            }
            steps {
                publishCoderrect "true"
                publishHTML (target : [allowMissing: false,
                    alwaysLinkToLastBuild: true,
                    keepAll: true,
                    reportDir: '.coderrect/report',
                    reportFiles: 'index.html',
                    reportName: 'Coderrect_race_report',
                    includes: '**/*',
                    reportTitles: 'The Coderrect Race Report']
                )
            }
        }
	}
}
