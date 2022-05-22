import { useRouter } from 'next/router';
import Seo from '../../components/Seo';

export default function Detail({ params }: any) {
	const [original_title, id] = params || [];

	return (
		<div>
			<Seo title={original_title} />
			<h4>{original_title || 'Loading...'}</h4>
		</div>
	);
}

export function getServerSideProps({ params: { params } }: any) {
	return {
		props: {
			params
		}
	};
}
